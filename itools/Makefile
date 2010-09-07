# $NetBSD: Makefile,v 1.1.1.1 2010/09/07 00:54:21 jihbed Exp $
#

DISTNAME=	itools-1.0
CATEGORIES=	time
MASTER_SITES=	http://garr.dl.sourceforge.net/project/arabeyes/ITL%20itools/itools-1.0/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://www.arabeyes.org/project.php?proj=ITL
COMMENT=	Islamic hijri date and prayer time utilities
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	perl

REPLACE_PERL+=	ireminder

INSTALLATION_DIRS=    bin ${PKGMANDIR}/man1


.include "../../wip/libitl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
