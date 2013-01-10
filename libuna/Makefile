# $NetBSD: Makefile,v 1.3 2013/01/10 15:50:39 othyro Exp $
#

DISTNAME=	libuna-alpha-20130103
PKGNAME=	${DISTNAME:S/alpha-//1}
CATEGORIES=	converters
MASTER_SITES=	http://libuna.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/libuna/
COMMENT=	Library to support Unicode and ASCII (byte string) conversions
LICENSE=	gnu-lgpl-v3

WRKSRC=		${WRKDIR}/libuna-20130103
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	msgfmt msgmerge pkg-config xgettext

PKGCONFIG_OVERRIDE+=	libuna.pc.in

.include "options.mk"

#.include "../../wip/libcerror/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
