# $NetBSD: Makefile,v 1.1 2012/09/10 23:52:19 othyro Exp $
#

DISTNAME=	mono-dbus-sharp-glib-v0.5-1-gf73a286
PKGNAME=	dbus-sharp-glib-0.5.1
CATEGORIES=	sysutils
MASTER_SITES=	http://github.com/mono/dbus-sharp-glib/tarball/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mono/dbus-sharp-glib
COMMENT=	Fork of ndesk-dbus-glib
LICENSE=	2-clause-bsd # ?

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none
WRKSRC=		${WRKDIR}/${DISTNAME:S/v0.5-1-g//}
USE_TOOLS+=	aclocal autoconf autoheader automake gmake

PKGCONFIG_OVERRIDE+=	dbus-sharp-glib-1.0.pc.in

pre-configure:
	cd ${WRKSRC} && ./autogen.sh --prefix=${PREFIX}

.include "../../wip/dbus-sharp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
