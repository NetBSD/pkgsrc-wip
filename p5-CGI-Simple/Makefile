# $NetBSD: Makefile,v 1.2 2005/07/26 05:58:12 jgoamakf Exp $

DISTNAME=		Cgi-Simple-0.077
PKGNAME=		p5-CGI-Simple-0.077
SVR4_PKGNAME=		p5cgs
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=		hiramatu@boreas.dti.ne.jp
HOMEPAGE=		http://search.cpan.org/dist/Cgi-Simple/
COMMENT=		Simple totally OO CGI interface that is CGI.pm compliant

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/CGI/Simple/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
