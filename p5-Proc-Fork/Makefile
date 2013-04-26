# $NetBSD: Makefile,v 1.3 2013/04/26 02:13:51 jgoamakf Exp $
#

DISTNAME=	Proc-Fork-0.802
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Proc/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Proc-Fork/
COMMENT=	Simple, intuitive interface to the fork() system call
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Exporter-Tidy-[0-9]*:../../wip/p5-Exporter-Tidy

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Proc/Fork/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
