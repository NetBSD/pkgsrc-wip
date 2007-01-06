# $NetBSD: Makefile,v 1.1 2007/01/06 09:59:49 cheusov Exp $

DISTNAME=		BSD-Resource-1.28
PKGNAME=		p5-BSD-Resource-1.28
CATEGORIES=		sysutils perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=BSD/}

MAINTAINER=		cheusov@tut.by
HOMEPAGE=		http://search.cpan.org/dist/BSD-Resource/
COMMENT=		BSD process resource limit and priority functions

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/BSD/Resource/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
