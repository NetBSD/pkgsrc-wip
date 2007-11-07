# $NetBSD: Makefile,v 1.2 2007/11/07 06:51:49 jgoamakf Exp $

DISTNAME=	Catalyst-Manual-5.701003
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	jfranz@bsdprojects.net
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-Manual/
COMMENT=	Manual for Catalyst

PERL5_REQD+=	5.8.0

PERL5_PACKLIST=	auto/Catalyst/Manual/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
