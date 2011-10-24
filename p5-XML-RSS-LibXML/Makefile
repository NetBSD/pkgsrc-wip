# $NetBSD: Makefile,v 1.2 2011/10/24 10:57:50 jgoamakf Exp $

DISTNAME=	XML-RSS-LibXML-0.3102
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	hiramatu@boreas.dti.ne.jp
HOMEPAGE=	http://search.cpan.org/dist/XML-RSS-LibXML/
COMMENT=	XML::RSS with XML::LibXML
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Class-Accessor:../../devel/p5-Class-Accessor
DEPENDS+=	p5-DateTime-Format-Mail:../../time/p5-DateTime-Format-Mail
DEPENDS+=	p5-DateTime-Format-W3CDTF:../../time/p5-DateTime-Format-W3CDTF
DEPENDS+=	p5-XML-LibXML>=1.66:../../textproc/p5-XML-LibXML
DEPENDS+=	p5-UNIVERSAL-require:../../devel/p5-UNIVERSAL-require

PERL5_PACKLIST=		auto/XML/RSS/LibXML/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
