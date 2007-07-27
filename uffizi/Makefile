# $NetBSD: Makefile,v 1.1 2007/07/27 18:33:11 cherrymathew Exp $
#

DISTNAME=	uffizi.txt
CATEGORIES=	www graphics perl5
MASTER_SITES=	http://jmason.org/software/uffizi/
EXTRACT_SUFX=   #	

MAINTAINER=	cherrymathew@users.sourceforge.net
HOMEPAGE=	http://jmason.org/software/uffizi/
COMMENT=	Generates photo galleries from directories of image files

DEPENDS+=	jhead-[0-9]*:../../graphics/jhead

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# none

USE_TOOLS+=             perl:run
REPLACE_PERL=           ${DISTNAME}
NO_BUILD=               yes

PKGNAME=                ${DISTNAME:S/.txt$//}

INSTALLATION_DIRS=      bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME} ${PREFIX}/bin/${PKGBASE}


.include 	"../../graphics/ImageMagick/buildlink3.mk"
.include	"../../graphics/jpeg/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
