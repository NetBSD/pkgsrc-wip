# $NetBSD: Makefile,v 1.2 2013/11/25 09:20:25 zul_ Exp $

VERSION=	1.1.0
PKGNAME=	opam-${VERSION}
DISTNAME=	opam-full-${VERSION}
CATEGORIES=	devel
MASTER_SITES=	http://www.ocamlpro.com/pub/
LICENSE=	gnu-gpl-v3


MAINTAINER=	degroote@NetBSD.org
HOMEPAGE=	http://opam.ocamlpro.com/
COMMENT=	Source-based package manager for OCaml

USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes

BUILD_DEPENDS+=		curl-[0-9]*:../../www/curl


.include "../../lang/ocaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
