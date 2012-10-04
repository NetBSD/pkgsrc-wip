# $NetBSD: Makefile,v 1.2 2012/10/04 19:11:58 asau Exp $

DISTNAME=	Quota-1.5.1
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	sysutils perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Quota/}

MAINTAINER=	evaldo@gardenali.biz
COMMENT=	Perl5 module interface to filesystem quotas

PKG_DESTDIR_SUPPORT=	none

PERL5_PACKLIST=		auto/Quota/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
