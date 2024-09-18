# $NetBSD$

DISTNAME=	ripgrep-all-0.10.6
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=phiresky/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/phiresky/ripgrep-all/
COMMENT=	Search tool that allows you to look for a regex in a multitude of file types
LICENSE=	gnu-agpl-v3

.include "cargo-depends.mk"

#RUST_REQ=	1.80.1
#Upstream does not state the required MSRV.
#This package is confirmed to build with Rust 1.80.1 on amd64

# Note:
# Depending on the functionality you want to acheive this package may
# need external programs. I've choosen not to add these by default
# since, some maybe considered too heavy.
#
# ffmpeg: for the ffmpeg adapter
# graphicsmagick: for the pdfpages adapter
# pandoc: for the pandoc adapter
# poppler: for the poppler adapter
# tesseract: for the tesseract adapter

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
