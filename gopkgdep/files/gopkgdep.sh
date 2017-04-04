#!/bin/sh
#
# output dependencies for a given Go package. Input is the GO_SRCPATH.

ME=$(basename $0)

if [ -z "$1" ]; then
	echo "Usage: $0 srcpath" >&2
	exit 1
fi


GOPATH=$(mktemp -d -t ${ME}) || exit 2
export GOPATH

echo "=> Downloading code for $1"
go get "$1/..."

echo "=> Recursive dependencies (excluding stdlib)"
go list -f '{{range .Deps}}{{.}}
{{end}}' "$1/..." \
	| sort -u \
	| xargs go list -e -f '{{if not .Standard}}{{.ImportPath}}{{end}}' \
	| grep -v "^$1"