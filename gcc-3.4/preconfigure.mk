	# Create compiler driver scripts in ${WRKDIR}.
	(cd ${WRKDIR}/.gcc/bin && \
	for _target_ in g++ c++ addr2name.awk cc cpp gcc gprcmd g77 \
		gnatclean gccbug gcj gcjh gcov gij gnat gnatbind gnatbl \
		gnatchop jv-convert gnatfind gnatkr gnatlink gnatls gnatmake \
		gnatname gnatprep gnatxref gpr2make grepjar \
		i386--netbsdelf2.0-c++ \
		i386--netbsdelf2.0-g++ \
		i386--netbsdelf2.0-gcc \
		i386--netbsdelf2.0-gcc-3.4.0 \
		i386--netbsdelf2.0-gcj \
		i386--netbsdelf2.0-gcjh \
		jar jcf-dump rmiregistry jv-scan rmic ; do \
		${ECHO} '#!${TOOLS_SHELL}' > $${_target_} && \
		${ECHO} -n "exec ${LOCALBASE}/gcc-3.4.0/bin/$${_target_}" >> $${_target_} && \
		${ECHO} ' "$$@"' >> $${_target_} && \
		${CHMOD} +x $${_target_}; \
	done )
