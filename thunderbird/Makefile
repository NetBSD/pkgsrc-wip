# $NetBSD: Makefile,v 1.1.1.1 2003/12/04 14:23:14 jgoamakf Exp $
#

MOZILLA=	thunderbird
MOZILLA_BIN=	thunderbird-bin
MOZ_VER=	0.3
EXTRACT_SUFX=	.tar.bz2
DISTNAME=	thunderbird-source-${MOZ_VER}
CATEGORIES=	mail
MASTER_SITES=	http://ftp.mozilla.org/pub/mozilla.org/thunderbird/releases/0.3/

MAINTAINER=	hiramatu@boreas.dti.ne.jp
HOMEPAGE=	http://www.mozilla.org/projects/thunderbird/
COMMENT=	Mail application using the XUL user interface language

CONFIGURE_ENV+= MOZ_THUNDERBIRD=1
MAKE_ENV+=      MOZ_THUNDERBIRD=1

.include "../../www/mozilla/Makefile.common"
