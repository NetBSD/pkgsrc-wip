# $NetBSD: Makefile,v 1.1.1.1 2006/03/03 09:54:59 jgoamakf Exp $

DISTNAME=		DB_File-Lock-0.05
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		databases perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=DB_File/}

MAINTAINER=		hiramatu@boreas.dti.ne.jp
HOMEPAGE=		http://search.cpan.org/dist/DB_File-Lock/
COMMENT=		Locking with flock wrapper for DB_File

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/DB_File/Lock/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
