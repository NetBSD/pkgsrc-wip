# $NetBSD: Makefile,v 1.1.1.1 2003/04/03 09:41:20 bmeurer Exp $

DISTNAME=		autoproject-0.17
CATEGORIES=		devel
MASTER_SITES=		http://www.mv.com/ipusers/vanzandt/

MAINTAINER=		benedikt.meurer@unix-ag.uni-siegen.de
HOMEPAGE=		http://www.mv.com/ipusers/vanzandt/
COMMENT=		Creates a skeleton source package for a new program

DEPENDS+=		autoconf>=2.57:../../devel/autoconf
DEPENDS+=		automake>=1.7:../../devel/automake
DEPENDS+=		bash>=2.0:../../shells/bash2
DEPENDS+=		sh-utils-[0-9]*:../../sysutils/sh-utils

GNU_CONFIGURE=		yes

.include "../../mk/bsd.pkg.mk"
