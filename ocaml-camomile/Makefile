# $NetBSD: Makefile,v 1.2 2014/10/27 04:03:11 jgoamakf Exp $

PKGNAME=	ocaml-${DISTNAME}
DISTNAME=	camomile-0.8.4
CATEGORIES=	converters
MASTER_SITES=	https://github.com/downloads/yoriyuki/Camomile/
EXTRACT_SUFX=   .tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/yoriyuki/Camomile/tree/master/Camomile
COMMENT=	Unicode library for ocaml
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=       ocaml-findlib-[0-9]*:../../devel/ocaml-findlib

USE_TOOLS+=     gmake

USE_LANGUAGES=  c
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--datadir="${DESTDIR}${PREFIX}/lib/ocaml/site-lib"

.include "../../lang/camlp4/buildlink3.mk"
.include "../../lang/ocaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
