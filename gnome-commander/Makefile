# $NetBSD: Makefile,v 1.4 2006/10/29 08:32:43 shattered Exp $
#

DISTNAME=		gnome-commander-1.2.0
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-commander/1.2/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc@blackmouse.biz
HOMEPAGE=		http://www.nongnu.org/gcmd/
COMMENT=		GNOME Commander is a fast and powerful graphical filemanager

USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_DIRS=		gnome2-1.6
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake intltool pkg-config perl

#Problem with heimdal, on which this package depends via another packages.
#Simple solution is delete link to fnmatch.h from work directory of package
#after make configure like this:
pre-build:
	${RM} -f ${WRKDIR}/.buildlink/include/krb5/fnmatch.h

.include "../../x11/gtk2/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../mk/bsd.pkg.mk"
