# $NetBSD: Makefile,v 1.1.1.1 2008/03/16 10:21:10 thomasklausner Exp $
#

DISTNAME=	nemo-0.2.1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.iola.dk/nemo/downloads/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.iola.dk/nemo/
COMMENT=	File manager based on labels and timestamps

# for stetic
DEPENDS+=	monodevelop-[0-9]*:../../devel/monodevelop

USE_DIRS+=	xdg-1.4
USE_LANGUAGES=	# C#
USE_TOOLS+=	gmake msgfmt pkg-config

.include "../../lang/mono/buildlink3.mk"
.include "../../x11/gnome-sharp/buildlink3.mk"
.include "../../x11/gtk2-sharp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
