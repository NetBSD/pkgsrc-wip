# $NetBSD: Makefile,v 1.3 2004/04/18 15:12:49 poppnk Exp $
#

DISTNAME=		gnump3d-2.7
CATEGORIES=		wip
MASTER_SITES=		http://savannah.gnu.org/download/gnump3d/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://savannah.gnu.org/download/gnump3d/
COMMENT=		The GNU Streaming MP3 / Media Server

USE_PKGINSTALL=		YES
RCD_SCRIPTS=		gnump3d
CONF_FILES=		${PREFIX}/etc/gnump3d/gnump3d.conf

USE_PERL5=		YES
USE_GNU_TOOLS+=		make
REPLACE_PERL=   	${WRKSRC}/bin/*
USE_BUILDLINK3=		yes

SUBST_CLASSES=		usr etc
SUBST_FILES=		bin/gnump3d-index bin/gnump3d-top bin/gnump3d2 etc/gnump3d.conf

SUBST_STAGE.usr=	pre-patch
SUBST_FILES.usr=	${SUBST_FILES}
SUBST_SED.usr=		-e s!/usr\/!${PREFIX}/!

SUBST_STAGE.etc=	pre-patch
SUBST_FILES.etc=	${SUBST_FILES}
SUBST_SED.etc=		-e s!/etc\/!${PREFIX}/etc/!

do-build:

pre-install:
	${FIND} ${WRKSRC} -type f -name \*.sav |${XARGS} ${RM} -f

.include "../../mk/bsd.pkg.mk"
