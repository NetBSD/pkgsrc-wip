# $NetBSD: Makefile,v 1.8 2012/09/28 22:07:35 asau Exp $
#

DISTNAME=	evernote-mode-0_41
PKGNAME=	${DISTNAME:S/_/./}
CATEGORIES=	editors net
MASTER_SITES=	http://emacs-evernote-mode.googlecode.com/files/
EXTRACT_SUFX=	.zip

MAINTAINER=	ryo_on@yk.rim.or.jp
HOMEPAGE=	http://code.google.com/p/emacs-evernote-mode/
COMMENT=	Refer and edit Evernote notes directly from Emacs
LICENSE=	apache-2.0

DEPENDS+=	${RUBY_PKGPREFIX}-gdbm>=${RUBY_VERSION_SUFFIX}:../../databases/ruby-gdbm

USE_LANGUAGES=	# none

DOCSDIR=		${PREFIX}/share/doc/${PKGBASE}
INSTALLATION_DIRS=	${DOCSDIR} \
			${EMACS_LISPPREFIX}

WRKSRC=			${WRKDIR}/${DISTNAME}/ruby
RUBY_VERSION_SUPPORTED=	21 # xxx untested
USE_RUBY_SETUP=		YES

DOCUMENTS=	readme_en.txt \
		readme_en.html \
		readme_en.org \
		readme_ja.html \
		readme_ja.txt \
		readme_ja.org

SUBST_CLASSES+=		ruby-cmd
SUBST_STAGE.ruby-cmd=	pre-configure
SUBST_FILES.ruby-cmd=	../evernote-mode.el
SUBST_SED.ruby-cmd=	-e 's/ruby/${RUBY_NAME}/'
SUBST_SED.ruby-cmd+=	-e 's/"ruby"/"${RUBY_NAME}"/'

post-install:
	${INSTALL_DATA} ${WRKSRC}/../evernote-mode.el \
		${DESTDIR}${EMACS_LISPPREFIX}
.for docfile in ${DOCUMENTS}
	${INSTALL_DATA} ${WRKSRC}/../doc/${docfile} \
		${DESTDIR}${DOCSDIR}
.endfor

.include "../../lang/ruby/modules.mk"
.include "../../editors/emacs/modules.mk"
.include "../../mk/bsd.pkg.mk"
