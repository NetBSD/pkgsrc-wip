# $NetBSD: Makefile,v 1.3 2011/10/11 07:46:42 jgoamakf Exp $

DISTNAME=		Petal-2.20
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5ptl
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../../authors/id/N/NI/NINE/}

MAINTAINER=		hiramatu@boreas.dti.ne.jp
HOMEPAGE=		http://search.cpan.org/dist/Petal/
COMMENT=		Perl Template Attribute Language
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-MKDoc-XML>=0.75:../../wip/p5-MKDoc-XML

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PKG_DESTDIR_SUPPORT=	user-destdir
PERL5_PACKLIST=		auto/Petal/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
