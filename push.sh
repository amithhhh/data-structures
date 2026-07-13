#!/bin/bash

set -e

REPO="/mnt/stone/DS"

cd "$REPO" || {
    echo "Repository not found: $REPO"
    exit 1
}

if [ -n "$1" ]; then
    MESSAGE="$1"
else
    MESSAGE="Auto commit: $(date '+%Y-%m-%d %H:%M:%S')"
fi

echo "Adding changed files..."

# Add each changed file individually
git status --porcelain | while IFS= read -r line; do
    FILE="${line:3}"
    echo "Adding: $FILE"
    git add -- "$FILE"
done

# Check if there is anything staged
if git diff --cached --quiet; then
    echo "No changes to commit."
    exit 0
fi

echo "Committing..."
git commit -m "$MESSAGE"

BRANCH=$(git branch --show-current)

echo "Pushing to origin/$BRANCH..."
git push origin "$BRANCH"

echo "Done!"
