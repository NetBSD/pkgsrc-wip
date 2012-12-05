# $NetBSD: Makefile,v 1.2 2012/12/05 04:29:12 othyro Exp $
#

DISTNAME=	libuna-alpha-20120630
PKGNAME=	${DISTNAME:S/alpha-//1}
CATEGORIES=	converters
MASTER_SITES=	http://libuna.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/libuna/
COMMENT=	Library to support Unicode and ASCII (byte string) conversions
LICENSE=	gnu-lgpl-v3

WRKSRC=		${WRKDIR}/libuna-20120630
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	msgfmt msgmerge pkg-config xgettext

PKGCONFIG_OVERRIDE+=	libuna.pc.in

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
