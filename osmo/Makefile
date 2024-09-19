# $NetBSD: Makefile,v 1.6 2015/02/20 10:59:45 rsmarples Exp $
#

DISTNAME=	osmo-0.2.12
PKGREVISION=	1
CATEGORIES=	misc time
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=osmo-pim/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://clayo.org/osmo/
COMMENT=	Personal organizer, calendar and task manager
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS=	gmake msgfmt pkg-config

# workaround problem in po Makefile
post-build:
.for m in bg ca cs da de el en_GB es fi fr gl gl_ES hu it ja lt nl pl pt pt_BR ro ru sv te tr uk ur ur_PK zh_CN
	${TOOLS_CMD.msgfmt} -c ${WRKSRC}/po/${m}.po -o ${WRKSRC}/po/${m}.mo
.endfor

.include "../../archivers/libarchive/buildlink3.mk"
.include "../../comms/libsyncml/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../wip/libgringotts/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../textproc/gtkspell/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../time/libical/buildlink3.mk"
.include "../../www/webkit24-gtk/buildlink3.mk"	# required for contacts
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
