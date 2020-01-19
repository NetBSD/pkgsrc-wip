# $NetBSD: Makefile,v 1.4 2013/01/10 15:11:34 othyro Exp $
#

DISTNAME=	emovix-0.9.0
PKGREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=movix/eMoviX/0.9/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://movix.sourceforge.net/
COMMENT=	Tiny GNU/Linux distribution that plays video files when booted
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LANGUAGES=	# none
USE_TOOLS+=	bash perl

REPLACE_BASH+=	mplayer-fonts/centralEU-cp1250/runme
REPLACE_BASH+=	mplayer-fonts/centralEU-iso-8859-2/runme
REPLACE_PERL+=	src/movix/mixer.pl src/movix/movix.pl src/movix/rc.lirc
REPLACE_PERL+=	src/movix/setHardware.pl scripts/mkmovixiso
REPLACE_PERL+=	scripts/movix-conf.in

SUBST_CLASSES+=		cp
SUBST_STAGE.cp=		pre-install
SUBST_FILES.cp=		Makefile
SUBST_SED.cp=		-e "s|cp -a {translations,mplayer-fonts,keyboard-i18n,backgrounds}|${CP} -RPp translations mplayer-fonts keyboard-i18n backgrounds|g"
SUBST_MESSAGE.cp=	Fixing hardcoded cp path

post-install:
	${CHMOD} -x ${DESTDIR}${PREFIX}/share/emovix/mplayer-fonts/turkish/*

.include "../../mk/bsd.pkg.mk"
