# $NetBSD: Makefile,v 1.1.1.1 2012/05/22 02:24:17 jeremy-c-reed Exp $
#

DISTNAME=	osmo-0.2.10
CATEGORIES=	misc time
MASTER_SITES=	 ${MASTER_SITE_SOURCEFORGE:=osmo-pim/osmo-0.2.10/}

MAINTAINER=	INSERT_YOUR_MAIL_ADDRESS_HERE
HOMEPAGE=	http://clayo.org/osmo/
COMMENT=	Personal organizer, calendar and task manager
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

CONFIGURE_ENV+=		LIBICAL_CFLAGS="-I${BUILDLINK_PREFIX.libical}/include/libical"
GNU_CONFIGURE=	yes
#USE_TOOLS=	msgfmt pkg-config
USE_TOOLS=	gmake msgfmt pkg-config

# TODO: consider following?
#    * Libtar library, version >= 1.2.10
#    * Libgringotts library, version >= 1.2.1 
#    * Libsyncml library, version >= 0.4.0

# workaround problem in po Makefile
post-build:
.for m in bg ca cs da de el en_GB es fi fr hu it ja lt nl pl pt ru sv tr uk zh_CN 
	${TOOLS_CMD.msgfmt} -c ${WRKSRC}/po/$m.po -o ${WRKSRC}/po/$m.mo
.endfor

.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../time/libical/buildlink3.mk"
.include "../../www/libgtkhtml/buildlink3.mk"	# required for contacts
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
