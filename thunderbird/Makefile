# $NetBSD: Makefile,v 1.3 2003/12/20 11:03:44 grantbeattie Exp $
#

MOZILLA=	thunderbird
MOZILLA_BIN=	thunderbird-bin
MOZ_VER=	0.4
EXTRACT_SUFX=	.tar.bz2
DISTNAME=	thunderbird-source-${MOZ_VER}
CATEGORIES=	mail
MASTER_SITES=	http://ftp.mozilla.org/pub/mozilla.org/thunderbird/releases/0.4/

MAINTAINER=	hiramatu@boreas.dti.ne.jp
HOMEPAGE=	http://www.mozilla.org/projects/thunderbird/
COMMENT=	Mail application using the XUL user interface language

CONFIGURE_ENV+= MOZ_THUNDERBIRD=1
MAKE_ENV+=      MOZ_THUNDERBIRD=1

.include "../../www/mozilla/Makefile.common"
