# $NetBSD: Makefile,v 1.4 2004/02/11 05:48:33 minskim Exp $
#

DISTNAME=	aget-0.4
CATEGORIES=	net
MASTER_SITES=	http://www.enderunix.org/aget/

MAINTAINER=	eeg@e3labs.ath.cx
HOMEPAGE=	http://www.enderunix.org/aget/
COMMENT=	Multithreaded HTTP download accelerator

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=	yes
NO_CONFIGURE=	yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
post-configure:
	(cd ${WRKSRC} && ${MV} Makefile.Solaris Makefile)
.endif

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/aget ${PREFIX}/bin/aget

PTHREAD_OPTS+=          require

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
