# $NetBSD: Makefile,v 1.1.1.1 2006/03/03 09:55:58 jgoamakf Exp $

DISTNAME=		Tie-DB_Lock-0.07
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		databases perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Tie/}

MAINTAINER=		hiramatu@boreas.dti.ne.jp
HOMEPAGE=		http://search.cpan.org/dist/Tie-DB_Lock/
COMMENT=		Ties hashes to databases using shared and exclusive locks

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Tie/DB_Lock/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
