# $NetBSD: Makefile,v 1.13 2006/03/14 01:27:59 jlamwww Exp $
#

DISTNAME=		gnump3d-2.9.7
CATEGORIES=		audio
MASTER_SITES=		http://savannah.gnu.org/download/gnump3d/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.gnu.org/software/gnump3d/
COMMENT=		The GNU Streaming MP3 / Media Server

CFGFILE=		${PKG_SYSCONFDIR}/gnump3d/gnump3d.conf
RCD_SCRIPTS=		gnump3d
CONF_FILES=		none ${CFGFILE}

USE_PERL5=		YES
USE_TOOLS+=		gmake
REPLACE_PERL=   	${WRKSRC}/bin/*
NO_BUILD=		yes

SUBST_CLASSES+=		gnump3d
SUBST_FILES.gnump3d=	bin/gnump3d-index bin/gnump3d-top bin/gnump3d2 \
			etc/gnump3d.conf
SUBST_STAGE.gnump3d=	pre-patch
SUBST_SED.gnump3d+=	-e s!/usr\/!${PREFIX}/!
SUBST_SED.gnump3d+=	-e s!/etc\/!${PREFIX}/etc/!

pre-install:
	${FIND} ${WRKSRC} -type f -name \*.sav |${XARGS} ${RM} -f

post-install:
	cp ${CFGFILE} ${CFGFILE}.default
	if [ -e ${CFGFILE}-orig ]; then cp ${CFGFILE}-orig ${CFGFILE} ; fi

.include "../../mk/bsd.pkg.mk"
