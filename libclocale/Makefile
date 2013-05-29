# $NetBSD: Makefile,v 1.1 2013/05/29 03:01:04 othyro Exp $

DISTNAME=	libclocale-alpha-20121224
PKGNAME=	${DISTNAME:S/-alpha//1}
CATEGORIES=	devel
MASTER_SITES=	http://libclocale.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/libclocale/
COMMENT=	Library for cross-platform C locale functions
LICENSE=	gnu-lgpl-v3

WRKSRC=		${WRKDIR}/libclocale-20121224
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	msgfmt msgmerge pkg-config xgettext

PKGCONFIG_OVERRIDE+=	libclocale.pc.in

.include "options.mk"

.include "../../wip/libcerror/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
