# $NetBSD: Makefile,v 1.1.1.1 2003/06/05 14:12:26 poppnk Exp $
#

DISTNAME=	psh-1.8
CATEGORIES=	shells
MASTER_SITES=	http://www.gregorpurdy.com/gregor/psh/

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://www.gregorpurdy.com/gregor/psh/
COMMENT=	Perl Shell combines Unix shell with the power of Perl

USE_BUILDLINK2=	YES
USE_PERL5=	YES
USE_PKGINSTALL=	YES
PKG_SHELL=	${PREFIX}/bin/psh

.include "../../lang/perl5/module.mk"
.include "../../lang/perl5/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
