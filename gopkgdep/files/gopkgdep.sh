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
OUT_TMPFILE=$(mktemp -t ${ME}-out) || exit 2

echo "=> Downloading code for $1"
go get -v "$1/..." 2> ${OUT_TMPFILE}

echo "=> Repositories downloaded"
awk '/\(download\)/ { print $1 }' ${OUT_TMPFILE}

echo "=> Recursive dependencies (excluding stdlib)"
go list -f '{{range .Deps}}{{.}}
{{end}}' "$1/..." \
	| sort -u \
	| xargs go list -e -f '{{if not .Standard}}{{.ImportPath}}{{end}}' \
	| grep -v "^$1"
