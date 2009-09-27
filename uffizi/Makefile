# $NetBSD: Makefile,v 1.7 2009/09/27 10:01:59 cherrymathew Exp $
#

DISTNAME=	uffizi
PKGNAME=	uffizi-0.7
CATEGORIES=	www graphics perl5
MASTER_SITES=	http://jmason.org/software/uffizi/
EXTRACT_SUFX=	.txt

WRKSRC=		${WRKDIR}

MAINTAINER=	cherrymathew@users.sourceforge.net
HOMEPAGE=	http://jmason.org/software/uffizi/
COMMENT=	Generates photo galleries from directories of image files

DEPENDS+=	jhead-[0-9]*:../../graphics/jhead
DEPENDS+=	p5-Image-Size>=3.2:../../graphics/p5-Image-Size

USE_LANGUAGES=	# none

USE_TOOLS+=		perl:run
REPLACE_PERL=		${DISTNAME}${EXTRACT_SUFX}
NO_BUILD=		yes

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME}${EXTRACT_SUFX} ${PREFIX}/bin/${PKGBASE}


.include 	"../../graphics/ImageMagick/buildlink3.mk"
.include	"../../graphics/jpeg/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
