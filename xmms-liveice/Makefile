# $NetBSD: Makefile,v 1.1.1.1 2003/05/03 17:28:46 xtraeme Exp $
#

DISTNAME=	liveice-xmms
PKGNAME=	xmms-liveice-1.0.0
WRKSRC=         ${WRKDIR}/LiveIce-1.0.0
CATEGORIES=	audio
MASTER_SITES=	http://star.arm.ac.uk/~spm/software/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://star.arm.ac.uk/~spm/software/
COMMENT=	Audio streaming plugin for XMMS

USE_BUILDLINK2=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../audio/xmms/buildlink2.mk"
.include "../../audio/lame/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
