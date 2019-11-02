# $NetBSD: Makefile,v 1.20 2019/08/27 19:56:03 schmonz Exp $

GITHUB_PROJECT=	ocaml-sha
DISTNAME=	sha-1.12
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=djs55/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ocaml-community/sedlex
COMMENT=	Ocaml SHA 1 and 2 family implementation
LICENSE=	isc

OCAML_USE_DUNE=	yes

.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
