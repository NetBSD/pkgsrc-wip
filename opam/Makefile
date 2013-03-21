# $NetBSD: Makefile,v 1.1 2013/03/21 20:09:45 zul_ Exp $

VERSION=	1.0.0
PKGNAME=	opam-${VERSION}
DISTNAME=	${VERSION}
CATEGORIES=	devel
MASTER_SITES=	https://github.com/OCamlPro/opam/archive/
LICENSE=	gnu-gpl-v3


MAINTAINER=	degroote@NetBSD.org
HOMEPAGE=	http://opam.ocamlpro.com/
COMMENT=	Source-based package manager for OCaml

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes

BUILD_DEPENDS+=		curl-[0-9]*:../../www/curl


.include "../../lang/ocaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
