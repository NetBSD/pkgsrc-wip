# $NetBSD: Makefile,v 1.1.1.1 2005/04/01 09:45:56 jgoamakf Exp $

DISTNAME=	Exporter-Lite-0.01
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5exl
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Exporter/}

MAINTAINER=	hiramatu@boreas.dti.ne.jp
HOMEPAGE=	http://search.cpan.org/dist/Exporter-Lite/
COMMENT=	Lightweight exporting of variables

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Exporter/Lite/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
