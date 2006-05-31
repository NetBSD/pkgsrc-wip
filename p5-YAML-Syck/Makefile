# $NetBSD: Makefile,v 1.1.1.1 2006/05/31 10:24:39 roelants Exp $
#

DISTNAME=		YAML-Syck-0.45
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=YAML/}

MAINTAINER=		dieter.NetBSD@pandora.be
HOMEPAGE=		http://search.cpan.org/~autrijus/${DISTNAME}/
COMMENT=		Fast, lightweight YAML loader and dumper

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/YAML/Syck/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
