# $NetBSD: Makefile,v 1.1.1.1 2007/12/10 09:19:37 netcap Exp $
#

DISTNAME=	Text-Trim-1.01
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	tonnerre@bsdprojects.net
HOMEPAGE=	http://search.cpan.org/dist/Text-Trim/
COMMENT=	Extract the structure of a quoted mail message

DEPENDS+=	p5-Test-Simple-[0-9]*:../../devel/p5-Test-Simple

PERL5_MODULE_TYPE=	Module::Build

PERL5_PACKLIST=	auto/Text/Trim/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
