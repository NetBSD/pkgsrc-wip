# $NetBSD: Makefile,v 1.4 2003/04/11 15:20:10 jmmv Exp $
#

DISTNAME=	Perl-Tidy-20021130
PKGNAME=	${DISTNAME:S/Perl-Tidy/perltidy/}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=perltidy/}

MAINTAINER=	virtus@wanadoo.nl
HOMEPAGE=	http://perltidy.sourceforge.net/
COMMENT=	Indents and reformats Perl scripts to make them easier to read

USE_BUILDLINK2=	YES
USE_PERL5=	YES
PERL_CONFIGURE= YES

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
