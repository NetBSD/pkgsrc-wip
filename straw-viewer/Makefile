# $NetBSD$

DISTNAME=	straw-viewer-0.0.7
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=trizen/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/trizen/straw-viewer/
COMMENT=	Search and play video from YouTube, using the API of invidio.us
LICENSE=	artistic-2.0

DEPENDS+=	p5-Data-Dump-[0-9]*:../../devel/p5-Data-Dump
DEPENDS+=	p5-JSON-[0-9]*:../../converters/p5-JSON
DEPENDS+=	p5-Term-ANSIColor-[0-9]*:../../devel/p5-Term-ANSIColor
DEPENDS+=	p5-Term-ReadKey-[0-9]*:../../devel/p5-Term-ReadKey

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/WWW/StrawViewer/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
