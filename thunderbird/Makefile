# $NetBSD: Makefile,v 1.4 2003/12/30 04:57:33 jgoamakf Exp $
#

MOZILLA=	thunderbird
MOZILLA_BIN=	thunderbird-bin
MOZ_VER=	0.4
EXTRACT_SUFX=	.tar.bz2
DISTNAME=	thunderbird-source-${MOZ_VER}
CATEGORIES=	mail
MASTER_SITES=	http://ftp.mozilla.org/pub/mozilla.org/thunderbird/releases/${MOZ_VER}/

MAINTAINER=	hiramatu@boreas.dti.ne.jp
HOMEPAGE=	http://www.mozilla.org/projects/thunderbird/
COMMENT=	Mail application using the XUL user interface language

CONFIGURE_ENV+= MOZ_THUNDERBIRD=1
MAKE_ENV+=      MOZ_THUNDERBIRD=1

CONFIGURE_ARGS+=        --enable-extensions=wallet,spellcheck,xmlextras

.include "../../www/mozilla/Makefile.common"
