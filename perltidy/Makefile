# $NetBSD: Makefile,v 1.5 2004/05/02 22:53:41 blef Exp $
#

DISTNAME=	Perl-Tidy-20021130
PKGNAME=	${DISTNAME:S/Perl-Tidy/perltidy/}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=perltidy/}

MAINTAINER=	virtus@wanadoo.nl
HOMEPAGE=	http://perltidy.sourceforge.net/
COMMENT=	Indents and reformats Perl scripts to make them easier to read

USE_BUILDLINK3=	YES
USE_PERL5=	YES
PERL_CONFIGURE= YES

PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Perl/Tidy/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
