## Pre-commit

You can apply pre-commit with following commands:

```bash
# Install pre-commit and clang-format
apt install pre-commit
apt install clang-format

# Apply pre-commit hooks
pre-commit install
```

You can apply pre-commit hooks for formatting in root directory when committing.

You can manually apply pre-commit hooks with following commands:
```bash
pre-commit run --all-files
```
