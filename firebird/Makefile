# $NetBSD: Makefile,v 1.14 2005/07/01 02:05:11 hisazumi Exp $
#

DISTNAME=		firebird-1.5.2.4731
CATEGORIES=		wip
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=firebird/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		nel@soraneko.com
HOMEPAGE=		http://jaist.dl.sourceforge.net/sourceforge/firebird/
COMMENT=		SQL database, opensource version of InterBase

DEPENDS=		autoconf>=2.58:../../devel/autoconf

USE_PKGLOCALEDIR=	yes
HAS_CONFIGURE=          yes
CONFIGURE_SCRIPT=       AUTOCONF=/usr/pkg/bin/autoconf ./autogen.sh
CONFIGURE_ARGS+=        --prefix=/usr/pkg/firebird
USE_TOOLS+=             gmake
USE_TOOLS+=             gm4
TOOLS_DEPMETHOD.gm4=    DEPENDS

PKG_USERS=		firebird:firebird
PKG_GROUPS=		firebird

.include "../../mk/bsd.pkg.mk"
