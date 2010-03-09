# $NetBSD: Makefile,v 1.1.1.1 2010/03/09 23:49:21 othyro Exp $
#

DISTNAME=	xml-light-2.2
CATEGORIES=	textproc
MASTER_SITES=	http://tech.motion-twin.com/zip/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tech.motion-twin.com/xmllight.html
COMMENT=	Xml-Light is a minimal XML parser & printer for OCaml
LICENSE=	gnu-lgpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/xml-light
USE_LANGUAGES=	c

.include "../../lang/ocaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
