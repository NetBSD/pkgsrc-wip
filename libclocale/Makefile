# $NetBSD: Makefile,v 1.2 2013/06/02 11:57:21 othyro Exp $

DISTNAME=	libclocale-experimental-20130602
PKGNAME=	${DISTNAME:S/-experimental//1}
CATEGORIES=	devel
MASTER_SITES=	http://libclocale.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/libclocale/
COMMENT=	Library for cross-platform C locale functions
LICENSE=	gnu-lgpl-v3

WRKSRC=		${WRKDIR}/libclocale-20130602
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	msgfmt msgmerge pkg-config xgettext

PKGCONFIG_OVERRIDE+=	libclocale.pc.in

.include "options.mk"

.include "../../wip/libcerror/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
