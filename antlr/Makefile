# $NetBSD$

###########################################################
#               Generated by fbsd2pkg                     #
###########################################################

###########################################################
# Unconverted and partially converted FreeBSD port syntax:

#CONFLICTS=		pccts-[0-9]*
#USE_JAVA=		yes
#JAVA_VERSION=		1.6+
#PORT_CLASSPATH=	${WRKSRC}/antlrall.jar:.
#SUB_FILES=		antlr.sh
#OPTIONS_DEFINE=	PYTHON DOCS
#OPTIONS_SUB=		yes
#.if ${PORT_OPTIONS:MPYTHON}
# Unknown tool: USE_TOOLS=	python
#PORTDOCS+=		python-runtime.html
#ANTLR_PYTHON=		${WRKSRC}/lib/python
#.endif
#post-configure:
#.if ${PORT_OPTIONS:MPYTHON}
#	(cd ${ANTLR_PYTHON} && ${PYTHON_CMD} setup.py config)
#.endif
#.if defined(WITH_BUILT_JAVA_LIB)
#pre-build:
#	(cd ${WRKSRC} && ${JAVA} -classpath "${PORT_CLASSPATH}" antlr.build.Tool build)
#	(cd ${WRKSRC} && ${JAVA} -classpath "${PORT_CLASSPATH}" antlr.build.Tool jar)
#.endif
#.if ${PORT_OPTIONS:MPYTHON}
#post-build:
#	(cd ${ANTLR_PYTHON} && ${PYTHON_CMD} setup.py build && \
#	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${ANTLR_PYTHON})
#.endif
#.if ${PORT_OPTIONS:MPYTHON}
#	@(cd ${ANTLR_PYTHON} && ${PYTHON_CMD} setup.py install --root=${DESTDIR})
#.endif

DISTNAME=	antlr-${PORTVERSION}
CATEGORIES=	devel
MASTER_SITES=	http://www.antlr2.org/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.antlr2.org/

COMMENT=	ANother Tool for Language Recognition
LICENSE=	public-domain

HAS_CONFIGURE=	yes
# Needs java and javac or gcj?
# On CentOS, yum install java-1.7.0-openjdk-devel.x86_64 or similar
# pkgsrc openjdk package does not build on Linux
# FIXME: Add a check here to notify users trying to install
USE_JAVA=	yes

CHECK_PORTABILITY_SKIP=	configure.in

# Just assuming C and C++: Adjust this!
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

CONFIGURE_ENV=	JAVAC="${JAVAC}" JAR="${JAR}" JAVA="${JAVA}" CLASSPATH="${PORT_CLASSPATH}"

CONFIGURE_ARGS=	--disable-csharp --prefix=${PREFIX}

CFLAGS.Linux+=	-fPIC

PORTVERSION=	2.7.7
DOCSDIR=	${PREFIX}/share/doc/antlr
PORTDOCS=	ANTLRException.gif closure.gif cpp-runtime.html \
		csharp-runtime.html err.html glossary.html hidden.stream.gif \
		index.html inheritance.html j-guru-blue.jpg jguru-logo.gif \
		lexer.html lexer.to.parser.tokens.gif logo.gif metalang.html \
		optional.gif options.html posclosure.gif runtime.html sor.html \
		stream.perspectives.gif stream.selector.gif \
		stream.splitter.gif streams.html subrule.gif trees.html \
		vocab.html

# /usr/ports/Mk/bsd/java.mk
JAVAJARDIR=	${PREFIX}/share/java/classes
JAVA_VERSION=	1.6

# Hack to simulate FreeBSD's SUB feature.  Is there a canonical way to handle
# this in pkgsrc?
SUBST_CLASSES+=	sh
SUBST_FILES.sh=	${WRKDIR}/antlr.sh
SUBST_STAGE.sh=	pre-configure
SUBST_SED.sh=	-e 's|%%JAVA_VERSION%%|${JAVA_VERSION}|'
SUBST_SED.sh+=	-e 's|%%LOCALBASE%%/bin/java|java|'
SUBST_SED.sh+=	-e 's|%%JAVAJARDIR%%|${JAVAJARDIR}|'

INSTALLATION_DIRS=	${JAVAJARDIR} bin include/antlr lib ${DOCSDIR}

post-extract:
	(cd ${WRKSRC} && ${CP} antlr.jar antlrall.jar)
	cp ${FILESDIR}/antlr.sh.in ${WRKDIR}/antlr.sh

do-install:
	${INSTALL_DATA} ${WRKSRC}/antlr.jar ${DESTDIR}${JAVAJARDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/antlr.sh ${DESTDIR}${PREFIX}/bin/antlr
	${INSTALL_DATA} ${WRKSRC}/lib/cpp/antlr/*.hpp \
		${DESTDIR}${PREFIX}/include/antlr
	${INSTALL_DATA} ${WRKSRC}/lib/cpp/src/libantlr.a ${DESTDIR}${PREFIX}/lib
	(cd ${WRKSRC}/doc && ${INSTALL_DATA} ${PORTDOCS} ${DESTDIR}${DOCSDIR})

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
