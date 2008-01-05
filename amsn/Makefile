# $NetBSD: Makefile,v 1.16 2008/01/05 17:02:02 cetrox Exp $
#

DISTNAME=		amsn-0.97
PKGNAME=		${DISTNAME:S/_/./}
CATEGORIES=		chat
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=amsn/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.amsn-project.net/
COMMENT=		"Alvaro's MSN messenger client"

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes

INSTALLATION_DIRS=	bin

USE_TOOLS+=		gmake perl:run bash:run
USE_LANGUAGES=		c c++
USE_DIRS+= 		xdg-1.4

REPLACE_INTERPRETER+=	sys-WISH
REPLACE.sys-WISH.old=	.*wish
REPLACE.sys-WISH.new=	${PREFIX}/bin/wish
REPLACE_FILES.sys-WISH=	alarm.tcl skins.tcl amsn-remote \
	utils/TkCximage/demos/demo.tcl utils/linux/capture/test.tcl \
	utils/pixmapprogbar/test.tcl utils/webcamsn/webcamsn.tcl

REPLACE_INTERPRETER+=	sys-TCLSH
REPLACE.sys-TCLSH.old=	.*tclsh
REPLACE.sys-TCLSH.new=	${PREFIX}/bin/tclsh
REPLACE_FILES.sys-TCLSH=amsn-remote-CLI lang/convert.tcl

REPLACE_PERL=		utils/amsnctl.pl lang/complete.pl \
	utils/linux/capture/structs/ioctl2desc \
	utils/linux/capture/structs/struct2desc
REPLACE_BASH=		utils/update-amsn.sh amsn lang/langchk.sh

CHECK_WRKREF_SKIP=	share/amsn/config.log

INSTALLATION_DIRS=	share/amsn share/pixmaps

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../security/tcl-tls/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
