# $NetBSD: Makefile,v 1.7 2005/05/20 20:05:01 rillig Exp $
#

DISTNAME=		gnump3d-2.8
CATEGORIES=		audio
MASTER_SITES=		http://savannah.gnu.org/download/gnump3d/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://savannah.gnu.org/download/gnump3d/
COMMENT=		The GNU Streaming MP3 / Media Server

USE_PKGINSTALL=		YES
RCD_SCRIPTS=		gnump3d
CONF_FILES=		none ${PREFIX}/etc/gnump3d/gnump3d.conf

USE_PERL5=		YES
USE_GNU_TOOLS+=		make
REPLACE_PERL=   	${WRKSRC}/bin/*
NO_BUILD=		yes

SUBST_CLASSES=		gnump3d
SUBST_FILES.gnump3d=	bin/gnump3d-index bin/gnump3d-top bin/gnump3d2 \
			etc/gnump3d.conf
SUBST_STAGE.gnump3d=	pre-patch
SUBST_SED.gnump3d+=	-e s!/usr\/!${PREFIX}/!
SUBST_SED.gnump3d+=	-e s!/etc\/!${PREFIX}/etc/!

pre-install:
	${FIND} ${WRKSRC} -type f -name \*.sav |${XARGS} ${RM} -f

.include "../../mk/bsd.pkg.mk"
