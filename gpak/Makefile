# $NetBSD: Makefile,v 1.2 2012/09/29 00:50:39 asau Exp $

DISTNAME=	gpak-0.0.1
CATEGORIES=	sysutils
MASTER_FILES=	# empty
DISTFILES=	# empty
COMMENT=	Small package installer

#EXTRACT_ONLY=	# empty
NO_CONFIGURE=	yes

DEPENDS+=	p5-Gtk2-GladeXML>=1.007:../../devel/p5-Gtk2-GladeXML
DEPENDS+=	p5-pkgsrc-Dewey>=1.0:../../pkgtools/p5-pkgsrc-Dewey

SUBST_CLASSES+=			fix-prefix
SUBST_STAGE.fix-prefix=		post-build
SUBST_MESSAGE.fix-prefix=	Fixing relative prefix
SUBST_FILES.fix-prefix=		gpak.pl
SUBST_SED.fix-prefix=		-e 's,gpak.glade,${PREFIX}/share/gpak.glade,'

do-build:
	${MKDIR} ${WRKSRC}
	${CP} ${FILESDIR}/gpak.pl ${WRKSRC}

do-install:
	${INSTALL} ${WRKSRC}/gpak.pl ${DESTDIR}${PREFIX}/bin
	${INSTALL} ${FILESDIR}/gpak.glade ${DESTDIR}${PREFIX}/share

.include "../../mk/bsd.pkg.mk"
