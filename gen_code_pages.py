import os
import json
import re
from pathlib import Path
import mkdocs_gen_files

nav = mkdocs_gen_files.Nav()

def natural_sort_key(path):
    return [int(text) if text.isdigit() else text.lower() for text in re.split(r'(\d+)', str(path))]

def extract_ipynb_code(path):
    try:
        with open(path, 'r', encoding='utf-8') as f:
            data = json.load(f)
        code_cells = [ "".join(c.get('source', [])) for c in data.get('cells', []) if c.get('cell_type') == 'code' ]
        return "\n\n# --- New Cell ---\n\n".join(code_cells)
    except:
        return "Error parsing Notebook."

def get_friendly_parts(parts):
    """Convert folder names to friendly titles in the navigation"""
    mapping = {
        'uni-notes': 'Uni',
        'pa': 'Algorithm Design',
        'ps': 'Probability & Statistics',
        'rc': 'Systems & Networking',
        'so': 'Operating Systems',
        'alo': 'Linear Algebra',
        'data-science-and-ml': 'Data Science',
    }
    return tuple(mapping.get(part, part) for part in parts)

all_paths = sorted(
    Path("docs").rglob("*"), 
    key=lambda p: (not p.is_dir(), natural_sort_key(p))
)

for path in all_paths:
    if any(x in path.parts for x in ["javascripts", ".ipynb_checkpoints", "venv", ".git", ".DS_Store"]):
        continue
    if path.is_dir():
        continue

    rel_path = path.relative_to("docs")
    friendly_parts = get_friendly_parts(rel_path.parts)
    
    if path.suffix in [".py", ".c", ".R", ".ipynb", ".cpp"]:
        virtual_file_path = Path("code_views") / rel_path.with_suffix(rel_path.suffix + ".md")
        
        with mkdocs_gen_files.open(virtual_file_path, "w") as f:
            f.write(f"# {path.name}\n\n")
            if path.suffix == ".ipynb":
                f.write("``` python\n" + extract_ipynb_code(path) + "\n```")
            else:
                lang = path.suffix[1:].lower()
                f.write(f"``` {lang}\n--8<-- \"{rel_path}\"\n```\n")
        
        nav[friendly_parts] = str(virtual_file_path)

    elif path.suffix == ".md" and path.name != "index.md":
        nav[friendly_parts] = str(rel_path)

with mkdocs_gen_files.open("SUMMARY.md", "w") as nav_file:
    nav_file.writelines(nav.build_literate_nav())