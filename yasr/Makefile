# $NetBSD: Makefile,v 1.5 2026/09/29 06:03:59 wiz Exp $

COMMITS=	156
DISTNAME=	yasr-0.0.0.${COMMITS}
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=mgorse/}
GITHUB_TAG=	4b1799010f0453d822e1d246ef06f5ca204c6bdc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mgorse/yasr
COMMENT=	Lightweight and portable screen reader
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=	c
USE_TOOLS=	pkg-config msgfmt xgettext

# Replace bash with sh in configuration example
SUBST_CLASSES+=		use-sh
SUBST_STAGE.use-sh=	pre-configure
SUBST_MESSAGE.use-sh=	Use sh instead of bash
SUBST_FILES.use-sh=	yasr/yasr.conf
SUBST_SED.use-sh=	-e 's,/bin/bash,/bin/sh,'

# Fix eflite path in configuration example
SUBST_CLASSES+=			fix-eflite
SUBST_STAGE.fix-eflite=		pre-configure
SUBST_MESSAGE.fix-eflite=	Fix eflite path
SUBST_FILES.fix-eflite=		yasr/yasr.conf
SUBST_SED.fix-eflite=		-e 's,/usr/local/bin/eflite,${PREFIX}/bin/eflite,'

.include "../../devel/meson/build.mk"
.include "../../audio/speech-dispatcher/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
